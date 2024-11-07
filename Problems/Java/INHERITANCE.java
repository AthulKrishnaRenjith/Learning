class Employee {
    String name, address, phoneNumber;
    int age, salary;

    void printSalary() {
        System.out.println("Salary:" + salary);
    }
}

class Officer extends Employee {
    String specialization = "Data analytics", department = "IT";

    void officerDetails() {
        System.out.println("DETAILS OF OFFICER");
        System.out.println("Name:" + name);
        System.out.println("Age:" + age);
        System.out.println("Phone number:" + phoneNumber);
        System.out.println("Address:" + address);
        printSalary();
        System.out.println("Specialization:" + specialization);
        System.out.println("Department:" + department);
    }
}

class Manager extends Employee {
    String specialization = "Software development", department = "IT";

    void managerDetails() {
        System.out.println("DETAILS OF MANAGER");
        System.out.println("Name:" + name);
        System.out.println("Age:" + age);
        System.out.println("Phone number:" + phoneNumber);
        System.out.println("Address:" + address);
        printSalary();
        System.out.println("Specialization:" + specialization);
        System.out.println("Department:" + department);
    }
}

class Main {
    public static void main(String args[]) {
        Officer of = new Officer();
        Manager m = new Manager();

        of.name = "Ram";
        of.address = "42, 5 Mile Tmr Road, Yeshwanthpur, Bangalore, Karnataka.";
        of.age = 30;
        of.phoneNumber = "9543758297";
        of.salary = 50000;

        m.name = "Raj";
        m.address = "2-4-4, M G Road, Hyderabad, Andhra Pradesh.";
        m.age = 28;
        m.phoneNumber = "9748267382";
        m.salary = 40000;

        of.officerDetails();
        m.managerDetails();
    }
}
