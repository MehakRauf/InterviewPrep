import java.util.ArrayList;
import java.util.List;

abstract class Employee {
    private String name;
    private int id;

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    abstract public double calculateSalary();

    @Override
    public String toString() {
        return "Employee[name =  " + name + " id = " + id + " salary = " + calculateSalary() + "]";
    }
}

class FullTimeEmployee extends Employee {
    private double monthlySalary;

    public FullTimeEmployee(String name, int id, double monthlySalary) {
        super(name, id);
        this.monthlySalary = monthlySalary;
    }

    @Override
    public double calculateSalary() {
        return monthlySalary;
    }
}

class PartTimeEmployee extends Employee {
    private int hoursWorked;
    private double hourlyRate;

    public PartTimeEmployee(String name, int id, int hoursWorked, double hourlyRate) {
        super(name, id);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    @Override
    public double calculateSalary() {
        return hourlyRate * hoursWorked;
    }
}

class PayrollSystem {
    List<Employee> employeeList;

    public PayrollSystem() {
        employeeList = new ArrayList<>();
    }

    public void addEmployee(Employee e) {
        employeeList.add(e);
    }

    public void deleteEmployee(int id) {
        Employee employeeDetails = null;
        for (Employee e : employeeList) {
            if (e.getId() == id) {
                employeeDetails = e;
            }
        }
        if (employeeDetails != null) {
            employeeList.remove(employeeDetails);
        }
    }

    public void printEmployees() {
        for (Employee e : employeeList) {
            System.out.println(e);
        }
    }
}

public class EmployeePayrollSystem {
    public static void main(String[] args) {
        PayrollSystem payrollSystem = new PayrollSystem();

        FullTimeEmployee emp1 = new FullTimeEmployee("John Doe", 101, 5000.0);
        PartTimeEmployee emp2 = new PartTimeEmployee("Jane Smith", 102, 30, 15.0);

        payrollSystem.addEmployee(emp1);
        payrollSystem.addEmployee(emp2);

        System.out.println("After adding the employees.");
        payrollSystem.printEmployees();

        System.out.println("After deleting the employee with id 102");
        payrollSystem.deleteEmployee(102);
        payrollSystem.printEmployees();
    }
}