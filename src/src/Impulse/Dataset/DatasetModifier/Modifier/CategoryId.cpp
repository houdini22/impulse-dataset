#include "../../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                void CategoryId::applyToColumn(int columnIndex) {
                    DatasetData samples = this->dataset.getSamples();
                    T_StringVector categories;
                    T_Size i = 0;

                    for (auto &sample : samples) {
                        T_String category = sample->getColumnToString(columnIndex);
                        if (std::find(categories.begin(), categories.end(), category) == categories.end()) {
                            categories.push_back(category);
                            sample->setColumn(columnIndex, i);
                            this->map[columnIndex][i] = category;
                            i++;
                        } else {
                            ptrdiff_t index = std::distance(categories.begin(),
                                                            std::find(categories.begin(), categories.end(), category));
                            sample->setColumn(columnIndex, (double) index);
                        }
                    }

                    this->itemsCount[columnIndex] = (int) categories.size();
                }

                void CategoryId::saveColumnMapTo(int columnIndex, T_String path) {
                    nlohmann::json result;
                    result["map"] = nlohmann::json::object();

                    for (auto &map : this->map[columnIndex]) {
                        result["map"][map.second] = map.first;
                    }

                    std::ofstream out(path);
                    out << result.dump();
                    out.close();
                }

                int CategoryId::getItemsCount(int columnIndex) {
                    return this->itemsCount[columnIndex];
                }
            }
        }
    }
}
