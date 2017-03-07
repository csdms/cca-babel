#
# Copyright(C) 2008, Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# Written by Thomas Epperly <epperly2@llnl.gov>
# UCRL-CODE-2002-043.
# All rights served.
#
# This file is part of Gantlet.  For details, see 
# http://www.llnl.gov/CASC/components/software.html or contact the author.
#
# Gantlet is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License (as published by 
# the Free Software Foundation) version 2.1 dated February 1999.
#
# Gantlet is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even IMPLIED WARRANTY OF MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the terms and conditions of
# the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software; if not, write to the Free Software Foundation, 
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# ADDITIONAL NOTICE:
# 
# A. This notice is required to be provided under our contract with the
#    U.S. Department of Energy (DOE).  This work was produced at the 
#    University of California, Lawrence Livermore National Laboratory
#    under Contract No. W-7405-ENG-48 with the DOE.
#
# B. Neither the United States Government nor the University of California
#    nor any of their employees make any warranty, express or implied, or
#    assumes any liability or responsibility for the accuracy, completeness, 
#    or usefulness of any information, apparatus, product, or process 
#    disclosed, or represents that its use would not infringe on 
#    privately-owned rights.
# 
# C. Also, reference herein to any specific commercial products, process, or
#    services by trade name, trademark, manufacturer or otherwise does not
#    necessarily constitute or imply its endoresement, recommendation, or
#    favoring by the United States Government or the University of California.
#    The views and opinions of authors expressed herein do not necessarily 
#    state or reflect those of the United States Government or the University
#    of California, and shall not be used for advertising or product 
#    endorsement purposes.
"""
Launch subprocesses with a timeout.
"""

from subprocess import Popen, PIPE
import threading
import time
from os import kill
from signal import SIGKILL

class TimeoutChild(threading.Thread):
  def __init__(self, child, timeout=300):
    threading.Thread.__init__(self)
    self.child = child
    self.timeout = timeout
    self.stopEv = threading.Event()

  def run(self):
    self.stopEv.wait(self.timeout)
    if (self.child.poll() == None):
      try:
        kill(self.child.pid, SIGKILL)
      except:
        pass # don't freak out if the kill doesn't work

  def stop(self):
    self.stopEv.set()

def LaunchTest(command, out1, out2):
  child = Popen(command, shell=True, stdout=PIPE)
  tc = TimeoutChild(child, 120)
  tc.start()
  for line in child.stdout.xreadlines():
    out1.write(line)
    out2.write(line)
  tc.stop()
  returncode = child.poll()
  tc.join()
  return returncode

if __name__ == "__main__":
  import sys
  print "Exited with status = " + str(LaunchTest("yes", sys.stdout, sys.stdout))
