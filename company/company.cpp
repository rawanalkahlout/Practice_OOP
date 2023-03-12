#include <iostream>
using namespace std;
class Employee {
protected:
    string name;
    int Emp_id;
   double salary;

public:
    
    Employee(string N_employee, int id , double salary_Emp) {
        name = N_employee;
        Emp_id = id;
        salary = salary_Emp;
    }
    //pure virtual function
    virtual float totalSalary() = 0;
    //virtual function
    virtual void print() {
        cout << "name Employee :  " << name << endl << "id Employee :" << Emp_id << endl << "salary :" << salary <<endl;
    }
        

};

class Sales : public Employee {
private:
    float goss_sales;
    float commission_rate;

public:
    Sales( float goss , float rate , string name_Emp, int id_Emp, double salary) :Employee(name_Emp, id_Emp, salary){
        
        goss_sales = goss;
        commission_rate = rate;
    }

    void set_gross_sales(float sales) {
        goss_sales = sales;
    }

    void set_commission_rate(float rate) {
        commission_rate = rate;
    }


    float totalSalary() {
        return (salary + goss_sales * commission_rate);
    }

    void print() {
        Employee::print();
        cout << "goss_sales :  " << goss_sales << endl << "commission_rate :" << commission_rate;
    }
 

};

class Engineer : public Employee {
private:
    string specialty_Eng;
    int experience_Eng;
    int overTime_hours_Eng;
    float overTime_hours_rate_Eng;

public:
     
    Engineer(string specialty, int experience , int overTime_hours , int overTime_hours_rate , string name_Emp, int id_Emp, double salary):Employee(name_Emp, id_Emp, salary){
        specialty_Eng = specialty;
        experience_Eng = experience;
        overTime_hours_Eng = overTime_hours;
        overTime_hours_rate_Eng = overTime_hours_rate;
    }
    void set_overTime_hour(int overTime_H) {
        overTime_hours_Eng = overTime_H;
    }

    void set_overTime_hour_rate(float overTime_hour_R) {
        overTime_hours_rate_Eng = overTime_hour_R;
    }

    float totalSalary() {
        return salary + (overTime_hours_Eng * overTime_hours_rate_Eng);
    }

    void print() {
        Employee::print();
        cout <<  "name Employee :  " << name << endl << "overTime_hours_rate_Eng :" << overTime_hours_rate_Eng;
    }

};

int main()
{
    Employee* pointer_Em;
    
    Sales S(20, 20, "rawan", 2023, 2000) ;
    Engineer E("eng", 20, 20, 30, "rawan", 2, 20.2);
    pointer_Em = &S;
    pointer_Em->print();
    pointer_Em = &E;
    pointer_Em->print();


   
    return 0;
}

