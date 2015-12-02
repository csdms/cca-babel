#include <string>
using namespace std;
#include "objarg_Employee.hxx"
#include "objarg_EmployeeArray.hxx"
#include "objarg_Basic.hxx"
#include "sidl_BaseClass.hxx"
#include "synch.hxx"


#define MYASSERT( AAA ) \
  tracker.startPart(++part_no); \
  tracker.writeComment(#AAA); \
  if ( AAA ) result = synch::ResultType_PASS; \
  else result = synch::ResultType_FAIL;  \
  tracker.endPart(part_no, result);

struct TmpData_t {
  string name;
  int    age;
  float  salary;
  char   status;
};

struct TmpData_t TmpData[] = {
  { "John Smith", 35, 75.7e3, 'c' },
  { "Jane Doe", 40, 85.5e3, 'm' },
  { "Ella Vader", 64, 144.2e3, 'r' },
  { "Marge Inovera", 32, 483.2e3, 's' },
  { "Hughy Louis Dewey", 45, 182.9e3, 'm' },
  { "Heywood Yubuzof", 12, 20.8e3, 'x' },
  { "Picov Andropov", 90, 120.6e3, 'r' }
};

int main() {
  synch::ResultType result = synch::ResultType_PASS; 
  synch::RegOut tracker = synch::RegOut::_create();
  int part_no = 0;
  int i;
  const int numEmp = sizeof(TmpData)/sizeof(struct TmpData_t);
  tracker.setExpectations(82);
  objarg::EmployeeArray a = objarg::EmployeeArray::_create();
  for(i = 0; i < numEmp; ++i) {
    objarg::Employee e = objarg::Employee::_create();
    MYASSERT(e.init(TmpData[i].name, TmpData[i].age, 
		    TmpData[i].salary, TmpData[i].status));
    MYASSERT(a.appendEmployee(e));
    MYASSERT(a.getLength() == (i+1));
    MYASSERT(e.isSame(a.at(i+1)));
    MYASSERT(e.getAge() == TmpData[i].age);
    MYASSERT(e.getSalary() == TmpData[i].salary);
    MYASSERT(e.getStatus() == TmpData[i].status);
  }
  for(i = 0; i < numEmp; ++i) {
    objarg::Employee e;
    int empInd = a.findByName(TmpData[i].name, e);
    MYASSERT(empInd == (i+1));
    if (empInd != 0) {
      MYASSERT(e.isSame(a.at(empInd)));
    }
  }
  objarg::Employee f = objarg::Employee::_create();
  f.init("Hire High", 21, 0, 's');
  MYASSERT(a.promoteToMaxSalary(f));
  MYASSERT(f.getSalary() == (float)483.2e3);
  MYASSERT(a.appendEmployee(f));
  f = objarg::Employee::_create();
  f.init("Amadeo Avogadro, conte di Quaregna", 225, 6.022045e23, 'd');
  MYASSERT(!a.promoteToMaxSalary(f));

  {
    ::objarg::Basic b = ::objarg::Basic::_create();
    ::sidl::BaseClass o, inValue;
    MYASSERT(b.passIn(o, FALSE));
    o = ::sidl::BaseClass::_create();
    MYASSERT(b.passIn(o, TRUE));
    MYASSERT(b.passIn(::sidl::BaseClass::_create(), TRUE));
    o = ::sidl::BaseClass();
    
    MYASSERT(b.passInOut(o, false, false, true));
    MYASSERT(o._is_nil());

    o = ::sidl::BaseClass::_create();
    MYASSERT(b.passInOut(o, true, false, false));
    MYASSERT(o._is_nil());
    
    o = ::sidl::BaseClass::_create();
    inValue = o;
    MYASSERT(b.passInOut(o, true, true, true));
    MYASSERT(inValue.isSame(o));

    o = ::sidl::BaseClass::_create();
    inValue = o;
    MYASSERT(b.passInOut(o, true, true, false));
    MYASSERT(!inValue.isSame(o));
    
    o = ::sidl::BaseClass();
    tracker.writeComment("b.passOut(o, false);");
    b.passOut(o, false);
    MYASSERT(o._not_nil());
    tracker.writeComment("b.passOut(o, true);");
    b.passOut(o, true);
    MYASSERT(o._is_nil());
    
    MYASSERT(b.retObject(true)._is_nil());
    MYASSERT(b.retObject(false)._not_nil());
  }

  tracker.close();
  return 0;
}
