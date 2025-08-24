#include <iostream>
using namespace std;


// FaceRecognition with only detector type
void FaceRecognition(string detectorType); // e.g., "Haar", "DNN", "MTCNN"

// FaceRecognition with detector type and scale factor
void FaceRecognition(string detectorType, double scaleFactor); // scaleFactor: 1.01 - 1.5

// FaceRecognition with detector type, scale factor, and minNeighbors
void FaceRecognition(string detectorType, double scaleFactor, int minNeighbors); // minNeighbors: 3 - 10

// FaceRecognition with detector type, scale factor, minNeighbors, and minFaceSize
void FaceRecognition(string detectorType, double scaleFactor, int minNeighbors, int minFaceSize); // minFaceSize: 20 - 100

// FaceRecognition with all parameters
void FaceRecognition(string detectorType, double scaleFactor, int minNeighbors, int minFaceSize, int cropSize); // cropSize: 112, 224


int main() {
    // Test calls to overloaded FaceRecognition functions
    FaceRecognition("Haar");

    FaceRecognition("Haar", 1.01);

    FaceRecognition("Haar", 1.01, 3);

    FaceRecognition("Haar", 1.01, 3, 25);

    FaceRecognition("Haar", 1.01, 3, 25, 112);

    return 0;
}


// Function Overloading Example: FaceRecognition with varying parameters
void FaceRecognition(
    string detectorType         //* e.g., "Haar", "DNN", "MTCNN"
) {
    cout << "FaceRecognition called with:\n";
    cout << "  detectorType: " << detectorType << endl;
}

// Overloaded function with additional parameters
void FaceRecognition(
    string detectorType,         //* e.g., "Haar", "DNN", "MTCNN"
    double scaleFactor           //* 1.01 - 1.5 (e.g., 1.1)
) {
    cout << "FaceRecognition called with:\n";
    cout << "  detectorType: " << detectorType << endl;
    cout << "  scaleFactor: " << scaleFactor << endl;
}

// Overloaded function with more parameters
void FaceRecognition(
    string detectorType,         //* e.g., "Haar", "DNN", "MTCNN"
    double scaleFactor,          //* 1.01 - 1.5 (e.g., 1.1)
    int minNeighbors             //* 3 - 10
) {
    cout << "FaceRecognition called with:\n";
    cout << "  detectorType: " << detectorType << endl;
    cout << "  scaleFactor: " << scaleFactor << endl;
    cout << "  minNeighbors: " << minNeighbors << endl;
}

// Overloaded function with even more parameters
void FaceRecognition(
    string detectorType,         //* e.g., "Haar", "DNN", "MTCNN"
    double scaleFactor,          //* 1.01 - 1.5 (e.g., 1.1)
    int minNeighbors,            //* 3 - 10
    int minFaceSize              //* 20 - 100 (pixels)
) {
    cout << "FaceRecognition called with:\n";
    cout << "  detectorType: " << detectorType << endl;
    cout << "  scaleFactor: " << scaleFactor << endl;
    cout << "  minNeighbors: " << minNeighbors << endl;
    cout << "  minFaceSize: " << minFaceSize << endl;
}

// Overloaded function with all parameters
void FaceRecognition(
    string detectorType,         //* e.g., "Haar", "DNN", "MTCNN"
    double scaleFactor,          //* 1.01 - 1.5 (e.g., 1.1)
    int minNeighbors,            //* 3 - 10
    int minFaceSize,             //* 20 - 100 (pixels)
    int cropSize                 //* 112, 224
) {
    cout << "FaceRecognition called with:\n";
    cout << "  detectorType: " << detectorType << endl;
    cout << "  scaleFactor: " << scaleFactor << endl;
    cout << "  minNeighbors: " << minNeighbors << endl;
    cout << "  minFaceSize: " << minFaceSize << endl;
    cout << "  cropSize: " << cropSize << endl;
}