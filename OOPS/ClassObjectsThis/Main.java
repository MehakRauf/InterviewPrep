class Student {
    String name;
    int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void getInfo() {
        System.out.println("The name of this Student is " + this.name);
        System.out.println("The age of this Student is " + this.age);
    }

}

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Mehak", 22);
        s1.age = 23;
        s1.getInfo();
    }
}