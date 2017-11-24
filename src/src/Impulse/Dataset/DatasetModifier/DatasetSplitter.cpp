#include "../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            DatasetSplitter::DatasetSplitter(SlicedDataset &dataset) : slicedDataset(dataset) {
                this->slicedDataset = dataset;
            }

            SplittedDataset DatasetSplitter::split(double ratio) {
                SplittedDataset result;

                for (T_Size i = 0; i < this->slicedDataset.input.getSize(); i++) {
                    double stepRatio = (i + 1) / (double) this->slicedDataset.input.getSize();
                    if (ratio >= stepRatio) {
                        result.primary.input.addSample(this->slicedDataset.input.getSampleAt(i));
                        result.primary.output.addSample(this->slicedDataset.output.getSampleAt(i));
                    } else {
                        result.secondary.input.addSample(this->slicedDataset.input.getSampleAt(i));
                        result.secondary.output.addSample(this->slicedDataset.output.getSampleAt(i));
                    }
                }

                return result;
            }
        }
    }
}
