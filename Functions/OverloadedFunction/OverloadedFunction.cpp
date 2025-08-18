#include <iostream>
using namespace std;


void FaceRecognition(string eyeColor) {

}

int main() {
    
    return 0;
}

/*
1. Face detection parameters
    Detector type: e.g., Haar cascades, DNN-based detectors (SSD/MicroNet, BlazeFace), MTCNN, etc.
    Input image size: width and height after resizing (often 300–640 px on the shorter side)
    Scale factor: image pyramid step size (e.g., 1.05, 1.1) for multi-scale detection
    Min neighbors / confidence threshold: pruning weaker detections
    Minimum face size: smallest face to detect (e.g., 20x20 to 40x40 px)
    Non-maximum suppression (NMS) threshold: overlap cutoff to merge detections
    Detector model path: path to model weights/config (e.g., .pb, .onnx, .xml/.bin)
    Color space handling: expected input channels (BGR vs RGB)
    Post-processing: bounding box refinement, landmark extraction (if supported)

2. Face alignment/landmarks (optional but common)
    Landmark model choice: 5-point, 68-point facial landmarks
    Input crop size for alignment: e.g., 112x112 or 160x160
    Alignment reference: target eye and mouth positions to normalize pose
    Output aligned face size: final crop/patch size after alignment

3. Face embedding / representation parameters
    Embedding model: which model to use (e.g., FaceNet, ArcFace, SphereFace, LightCNN)
    Input size for embedding: e.g., 112x112, 160x160
    Preprocessing: color normalization, mean/subtract, scaling
    Normalization: L2 normalize embeddings or not
    Output dimension: e.g., 128-d, 512-d
    Model path / backend: ONNX, TensorRT engine, OpenVINO, PyTorch, etc.
    Inference precision: FP32, FP16, INT8 (for speed/memory)
    Batch size: number of face crops processed per inference
    Cropping strategy: whether to use the whole detected bbox or an aligned face patch

4. Database / comparison parameters
    Distance metric: cosine, Euclidean (L2), Manhattan
    Matching threshold: decision boundary for a match
    Database structure: map of identity -> embedding vector or a matrix
    Optional normalization: pre-normalize database embeddings for cosine

5. Miscellaneous and deployment
    Hardware acceleration: CPU, GPU, or dedicated accelerators
    Threading model: number of parallel detections/enrollments
    Logging / debugging flags: verbose, intermediate data
    Temporal smoothing (video): moving average of detections, track IDs
    Privacy and security: hashing or encrypting stored embeddings (if required)

How to choose defaults (practical starting points)
    Detector: OpenCV DNN with a lightweight model or a small MTCNN; input 300–416 px
    Min face size: 40–60 px for web camera streams; smaller for high-res videos
    Confidence threshold: 0.6–0.8 (adjust for false positives)
    Embedding dimension: 128 or 512 depending on model
    Preprocessing: standardize to mean 0, std 1 or model-specific means
    Distance threshold: cosine similarity threshold around 0.5–0.6 for cosine (depending on embedding norm); 
    Euclidean threshold around 0.6–1.0 normalized per model
*/