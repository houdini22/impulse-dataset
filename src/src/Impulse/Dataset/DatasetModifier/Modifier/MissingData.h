#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_MISSINGDATA_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_MISSINGDATA_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class MissingData : public Abstract {
                protected:
                    T_String modificationType = "mean";

                public:
                    explicit MissingData(Dataset &dataset) : Abstract(dataset) {}

                    void setModificationType(T_String type);

                    void applyToColumn(int columnIndex) override;
                };
            }
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_MISSINGDATA_H
