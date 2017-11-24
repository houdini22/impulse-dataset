#ifndef IMPULSE_ML_DATASET_CSVEXPORTER_H
#define IMPULSE_ML_DATASET_CSVEXPORTER_H

#include "../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetExporter {

            class CSVExporter : public Abstract {
            public:
                CSVExporter(Dataset &dataset);

                void exportTo(T_String path);
            };
        }
    }
}

#endif //IMPULSE_ML_DATASET_CSVEXPORTER_H
