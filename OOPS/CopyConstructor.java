class Student {
    String name;
    int age;

    Student(Student s2) {
        this.name = s2.name;
        this.age = s2.age;
    }

    Student() {
    }

    public void getInfo() {
        System.out.println("The name of this Student is " + this.name);
        System.out.println("The age of this Student is " + this.age);
    }

}

public class CopyConstructor {
    public static void main(String[] args) {
        Student s2 = new Student();
        s2.name = "Ali";
        s2.age = 30;
        Student s1 = new Student(s2);
        s1.getInfo();
    }
}
