#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORYID_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORYID_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class CategoryId : public Abstract {
                protected:
                    std::map<int, std::map<int, T_String>> map;
                public:
                    explicit CategoryId(Dataset &dataset) : Abstract(dataset) {}

                    void applyToColumn(int columnIndex) override;

                    void saveColumnMapTo(int columnIndex, T_String path);
                };
            }
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORYID_H
