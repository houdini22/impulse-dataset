#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORYID_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORYID_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class CategoryId : public Abstract {
                public:
                    explicit CategoryId(Dataset &dataset) : Abstract(dataset) {}

                    void applyToColumn(int columnIndex) override;
                };
            }
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORYID_H
