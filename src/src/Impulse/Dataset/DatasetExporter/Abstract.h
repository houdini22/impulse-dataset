#ifndef IMPULSE_ML_DATASET_ABSTRACT_H
#define IMPULSE_ML_DATASET_ABSTRACT_H

#include "../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetExporter {

            class Abstract {
            protected:
                Dataset &dataset;
            public:
                Abstract(Dataset &dataset);

                virtual void exportTo(T_String path) = 0;
            };
        }
    }
}

#endif //IMPULSE_ML_DATASET_ABSTRACT_H
