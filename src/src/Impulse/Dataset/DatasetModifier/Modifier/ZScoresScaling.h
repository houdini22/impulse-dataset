#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_ZSCORESSCALING_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_ZSCORESSCALING_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class ZScoresScaling : public Abstract {
                public:
                    explicit ZScoresScaling(Dataset &dataset) : Abstract(dataset) {}

                    ~ZScoresScaling() override = default;

                    void applyToColumn(int columnIndex) override;
                };
            }
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_ZSCORESSCALING_H
