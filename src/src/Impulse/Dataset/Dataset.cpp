#include "include.h"

namespace Impulse {

    namespace Dataset {

        Dataset::~Dataset() {
            this->data.clear();
        }

        void Dataset::addSample(DatasetSampleContainer sample) {
            this->data.push_back(sample);
        }

        void Dataset::removeSample(T_Size index) {
            this->data.erase(this->data.begin() + index);
        }

        void Dataset::out(T_Size limit) {
            for (T_Size i = 0; i < this->getSize(); i++) {
                if (limit > 0)
                    if (i + 1 == limit)
                        break;

                this->getSampleAt(i)->out();
            }
            std::cout << "---" << std::endl;
        }

        DatasetData &Dataset::getSamples() {
            return this->data;
        }

        DatasetSampleContainer Dataset::getSampleAt(int index) {
            return this->data.at(static_cast<unsigned long>(index));
        }

        T_Size Dataset::getSize() {
            return (T_Size) this->data.size();
        }

        T_Size Dataset::getColumnsSize() {
            if (this->getSize() > 0) {
                return this->getSampleAt(0)->getSize();
            }
            return 0;
        }

        Eigen::MatrixXd Dataset::exportToEigen() {
            DatasetData samples = this->getSamples();
            int row = 0;
            Eigen::MatrixXd result;

            result.resize(this->getSize(), this->getColumnsSize());
            for (auto &sample : samples) {
                result.row(row++) = sample->exportToEigen();
            }

            return result;
        }

        void Dataset::changeOrdering(std::initializer_list<int> columns) {
            for (T_Size i = 0; i < this->getSize(); i++) {
                this->getSampleAt(i)->changeOrdering(columns);
            }
        }
    }
}
