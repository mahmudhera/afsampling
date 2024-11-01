# include "FracMinHashSketch.h"

// Getter implementation
std::vector<hash_t> FracMinHashSketch::get() const {
    // call base class get method
    return Sketch::get();
}


// Adds a single element to the vector
void FracMinHashSketch::add(hash_t value) {
    // if hash value is smaller than threshold, add it to the vector
    if (value < threshold_) {
        Sketch::add(value);
    }
}


// Setter implementation; not expected to be used
void FracMinHashSketch::set(const std::vector<hash_t>& vec) {
    // clear the map
    data_.clear();
    for (hash_t value : vec) {
        // if hash value is smaller than threshold, add it to the vector
        if (value < threshold_) {
            Sketch::add(value);
        }
    }
}