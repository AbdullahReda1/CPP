#include <iostream>
using namespace std;

/*
    Polymorphism Example (Compile-time / Function Overloading in OOP)
    -----------------------------------------------------------------
    - We use a class `FaceRecognizer` that provides multiple `recognize` methods.
    - Methods share the same name but differ in parameter lists (overloading).
    - This is resolved at COMPILE-TIME (static polymorphism).
*/

class FaceRecognizer {
public:
    // Recognize using only detector type
    void recognize(string detectorType) {
        cout << "FaceRecognition called with:\n";
        cout << "  detectorType: " << detectorType << endl;
    }

    // Recognize using detector type + scale factor
    void recognize(string detectorType, double scaleFactor) {
        cout << "FaceRecognition called with:\n";
        cout << "  detectorType: " << detectorType << endl;
        cout << "  scaleFactor: " << scaleFactor << endl;
    }

    // Recognize with detector type, scale factor, and minNeighbors
    void recognize(string detectorType, double scaleFactor, int minNeighbors) {
        cout << "FaceRecognition called with:\n";
        cout << "  detectorType: " << detectorType << endl;
        cout << "  scaleFactor: " << scaleFactor << endl;
        cout << "  minNeighbors: " << minNeighbors << endl;
    }

    // Recognize with detector type, scale factor, minNeighbors, and minFaceSize
    void recognize(string detectorType, double scaleFactor, int minNeighbors, int minFaceSize) {
        cout << "FaceRecognition called with:\n";
        cout << "  detectorType: " << detectorType << endl;
        cout << "  scaleFactor: " << scaleFactor << endl;
        cout << "  minNeighbors: " << minNeighbors << endl;
        cout << "  minFaceSize: " << minFaceSize << endl;
    }

    // Recognize with all parameters
    void recognize(string detectorType, double scaleFactor, int minNeighbors, int minFaceSize, int cropSize) {
        cout << "FaceRecognition called with:\n";
        cout << "  detectorType: " << detectorType << endl;
        cout << "  scaleFactor: " << scaleFactor << endl;
        cout << "  minNeighbors: " << minNeighbors << endl;
        cout << "  minFaceSize: " << minFaceSize << endl;
        cout << "  cropSize: " << cropSize << endl;
    }
};

int main() {
    /*
        CPU + Memory Perspective
        ------------------------
        1. Stack allocates object `recognizer`.
        2. At compile-time, compiler checks the function signatures.
        3. Based on the number/type of arguments in each call,
            the compiler selects the correct overloaded version.
        4. Binding happens at COMPILE-TIME (static binding).
    */

    FaceRecognizer recognizer;

    // Different versions selected at compile time
    recognizer.recognize("Haar");
    recognizer.recognize("Haar", 1.01);
    recognizer.recognize("Haar", 1.01, 3);
    recognizer.recognize("Haar", 1.01, 3, 25);
    recognizer.recognize("Haar", 1.01, 3, 25, 112);

    return 0;
}