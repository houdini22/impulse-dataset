#ifndef IMPULSE_DATASET_DATASETMODIFIER_DATASETSPLITTER_H_
#define IMPULSE_DATASET_DATASETMODIFIER_DATASETSPLITTER_H_

#include "../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        struct SplittedDataset {
            SlicedDataset primary;
            SlicedDataset secondary;
        };

        namespace DatasetModifier {

            class DatasetSplitter {
            protected:
                SlicedDataset &slicedDataset;

            public:
                explicit DatasetSplitter(SlicedDataset &slicedDataset);

                SplittedDataset split(double ratio);
            };
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_DATASETSPLITTER_H_
