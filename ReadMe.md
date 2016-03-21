### c++ jni compattible test library
This is a simple Visual Studio c++ library project, generating `JniTest.dll`. This library is compattible with JNI. If you are using linux go to `./linux` folder.

### Necessary set up
* Set `JAVA_HOME` environment variable pointing to JDK folder

### How to generate JNI compatible source files
You want to be able to call methods from the c++ library from Java. This means you need to have the right method signature on the c++ methods so they are JNI compatible. Lucky for us, there is a tool for that.

Imagine there's a java file:
```Java
// JNIFoo.java
public class JNIFoo {    
    public native void nativeFoo();    

    static {
        System.loadLibrary("JniTest"); //this will be the generated JniTest.dll from this project
    }
    
    public static void main(String[] args) {
    	nativeFoo();
    }
}
```

* Compile the java file `javac JNIFoo.java`
* Generate C source file `javah -jni -cp path/to/root/class/dir JNIFoo`, this will generate a file you can include in this c++ project.
* build the library including generated file from the previous step
