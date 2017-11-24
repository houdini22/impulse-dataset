#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CALLBACK_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CALLBACK_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class Callback : public Abstract {
                protected:
                    std::function<T_String(T_String)> callback;

                public:
                    explicit Callback(Dataset &dataset) : Abstract(dataset) {}

                    void setCallback(std::function<T_String(T_String)> cb);

                    void applyToColumn(int columnIndex) override;
                };
            }
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CALLBACK_H
