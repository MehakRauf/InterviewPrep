class Student {
    String name;
    int age;

    Student() {
        this.name = "Fatima";
        this.age = 22;
        System.out.println("The name and age of the student are " + this.name + " and " + this.age + " respectively");
    }
}

public class NonParameterized {
    public static void main(String[] args) {
        Student s1 = new Student();
        
    }
}
