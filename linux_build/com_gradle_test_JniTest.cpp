#include <jni.h>
#include <iostream>
/* Header for class com_gradle_test_JniTest */

#ifndef _Included_com_gradle_test_JniTest
#define _Included_com_gradle_test_JniTest
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_gradle_test_JniTest
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_gradle_test_JniTest_start(JNIEnv *env, jobject obj) {
	printf("\nC++: Call from: Java_com_gradle_test_JniTest_start");

	jclass jniTestClass = env->FindClass("com/gradle/test/JniTest");
	jmethodID gtcID = env->GetMethodID(jniTestClass, "getTestClass", "()Lcom/gradle/test/TestClass;");

	printf("\nC++: get instance of TestClass from com/gradle/test/JniTest class");
	jobject testClassObj = env->CallObjectMethod(obj, gtcID);

	jclass testClass = env->FindClass("com/gradle/test/TestClass");
	jmethodID getSVFI = env->GetMethodID(testClass, "getStaticVariableFromInterface", "()V");
	jmethodID getSVFII = env->GetMethodID(testClass, "getStaticVariableFromInterfaceInt", "()I");

	printf("\nC++: calling getStaticVariableFromInterface method from com/gradle/test/TestClass");
	env->CallVoidMethod(testClassObj, getSVFI);

	printf("\nC++: calling getStaticVariableFromInterfaceInt method from com/gradle/test/TestClass");
	jint res = env->CallIntMethod(testClassObj, getSVFII);
	printf("\nC++: result value after call is: %d", res);

	return;
}

#ifdef __cplusplus
}
#endif
#endif
