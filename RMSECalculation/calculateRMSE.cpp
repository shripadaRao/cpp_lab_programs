#include <iostream>
#include <cmath>
#include <vector>

double rmse(const std::vector<double>& predicted, const std::vector<double>& actual) {
    if (predicted.size() != actual.size()) {
        std::cout << "Error: predicted and actual lists must have the same size" << std::endl;
        return -1;
    }
    double sum = 0;
    for (int i = 0; i < predicted.size(); i++) {
        sum += pow(predicted[i] - actual[i], 2);
    }
    return sqrt(sum / predicted.size());
}

int main() {
    std::vector<double> predicted = {1.0, 2.0, 3.0};
    std::vector<double> actual = {0.5, 1.5, 2.5};
    double error = rmse(predicted, actual);
    std::cout << "RMSE: " << error << std::endl;
    return 0;
}
