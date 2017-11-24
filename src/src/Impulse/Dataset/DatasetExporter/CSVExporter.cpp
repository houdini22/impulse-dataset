#include "../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetExporter {

            CSVExporter::CSVExporter(Dataset &dataset) : Abstract(dataset) {}

            void CSVExporter::exportTo(T_String path) {
                std::ofstream ofs (path, std::ofstream::out);

                for(T_Size i = 0; i < this->dataset.getSize(); i++) {
                    ofs << toString(this->dataset.getSampleAt(i)->getColumnToDouble(0));
                    for(T_Size j = 1; j < this->dataset.getSampleAt(i)->getSize(); j++) {
                        ofs << ",";
                        ofs << toString(this->dataset.getSampleAt(i)->getColumnToDouble(j));
                    }
                    ofs << std::endl;
                }

                ofs.close();
            }
        }
    }
}