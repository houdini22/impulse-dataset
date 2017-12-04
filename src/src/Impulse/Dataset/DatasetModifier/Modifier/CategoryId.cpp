#include "../../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                void CategoryId::applyToColumn(int columnIndex) {
                    DatasetData samples = this->dataset.getSamples();
                    T_StringVector categories;

                    for (auto &sample : samples) {
                        T_String category = sample->getColumnToString(columnIndex);
                        if (std::find(categories.begin(), categories.end(), category) == categories.end()) {
                            categories.push_back(category);
                        }
                    }

                    for (auto &sample : samples) {
                        T_String existingCategory = sample->getColumnToString(columnIndex);
                        for (T_Size j = 0; j < categories.size(); j++) {
                            if (categories.at(j) == existingCategory) {
                                sample->setColumn(columnIndex, j);
                                this->map[columnIndex][j] = existingCategory;
                            }
                        }
                    }
                }

                void CategoryId::saveColumnMapTo(int columnIndex, T_String path) {
                    nlohmann::json result;
                    result["map"] = nlohmann::json::object();

                    for(auto &map : this->map[columnIndex]) {
                        result["map"][map.second] = map.first;
                    }

                    std::ofstream out(path);
                    out << result.dump();
                    out.close();
                }
            }
        }
    }
}
