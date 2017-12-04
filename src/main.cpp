#include "src/Impulse/Dataset/include.h"
#include <sys/stat.h>

using namespace Impulse::Dataset;
using namespace std::chrono;

void test1() {
    auto start = std::chrono::system_clock::now();

    // build dataset from csv...
    DatasetBuilder::CSVBuilder builder("/home/hud/projekty/impulse-ml-dataset/src/data/data.csv");
    Dataset dataset = builder.build();
    dataset.out();

    // slice dataset to input and output set
    DatasetModifier::DatasetSlicer datasetSlicer(dataset);
    datasetSlicer.addInputColumn(0);
    datasetSlicer.addInputColumn(1);
    datasetSlicer.addInputColumn(2);
    datasetSlicer.addOutputColumn(3);

    SlicedDataset slicedDataset = datasetSlicer.slice();
    Dataset input = slicedDataset.input;
    Dataset output = slicedDataset.output;

    // fill missing data by mean of fields
    DatasetModifier::Modifier::MissingData missingDataModifier(input);
    missingDataModifier.setModificationType("mean");
    missingDataModifier.applyToColumn(1);
    missingDataModifier.applyToColumn(2);
    input.out();

    // create categories
    DatasetModifier::Modifier::Category categoryModifier(input);
    categoryModifier.applyToColumn(0);
    input.out();


    // modify "Yes" and "No" to numbers
    DatasetModifier::Modifier::Callback callbackModifier(output);
    callbackModifier.setCallback([](T_String oldValue) -> T_String {
        if (oldValue.find("Yes") != T_String::npos) {
            return "1";
        }
        return "0";
    });
    callbackModifier.applyToColumn(0);
    output.out();

    // scale all input
    DatasetModifier::Modifier::ZScoresScaling zScoresModifier(input);
    zScoresModifier.apply();
    input.out();

    DatasetModifier::DatasetSplitter datasetSplitter(slicedDataset);
    SplittedDataset splittedDataset = datasetSplitter.split(0.8);

    splittedDataset.primary.input.out();
    splittedDataset.primary.output.out();
    splittedDataset.secondary.input.out();
    splittedDataset.secondary.output.out();

    auto end = std::chrono::system_clock::now();
    long elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << elapsed_seconds << std::endl;

    DatasetExporter::CSVExporter exporter(input);
    exporter.exportTo("/home/hud/projekty/impulse-ml-dataset/src/data/export.csv");
}

void test2() {
    DatasetBuilder::CSVBuilder builder("/home/hud/projekty/impulse-ml-dataset/src/data/data2.csv");
    Dataset dataset = builder.build();
    dataset.out();

    DatasetModifier::Modifier::CategoryId categoryId(dataset);
    categoryId.applyToColumn(0);
    categoryId.applyToColumn(1);
    dataset.out();

    categoryId.saveColumnMapTo(0, "/home/hud/projekty/impulse-ml-dataset-private/src/data/map0.json");
    categoryId.saveColumnMapTo(1, "/home/hud/projekty/impulse-ml-dataset-private/src/data/map1.json");
}

void test3() {
    DatasetBuilder::CSVBuilder builder("/home/hud/projekty/impulse-ml-dataset/src/data/data3.csv");
    Dataset dataset = builder.build();
    dataset.out();

    DatasetModifier::Modifier::MinMaxScaling minMaxScaling(dataset);
    minMaxScaling.apply();
    dataset.out();
}

void test4() {
    DatasetBuilder::CSVBuilder builder("/home/hud/projekty/impulse-ml-dataset/src/data/data3.csv");
    Dataset dataset = builder.build();
    std::cout << dataset.exportToEigen() << std::endl;
}

void test5() {
    DatasetBuilder::CSVBuilder builder("/home/hud/projekty/impulse-ml-dataset-private/src/data/data2.csv");
    Dataset dataset = builder.build();
    dataset.out();
    dataset.changeOrdering({0, 1, 2});

    DatasetModifier::Modifier::CategoryId modifier(dataset);
    modifier.applyToColumn(0);
    modifier.applyToColumn(1);

    dataset.out(50);
}

void run(int argc, char *argv[]) {
    std::vector<T_String> params(argv, argv + argc);

    DatasetBuilder::CSVBuilder builder(params.at(1));
    Dataset dataset = builder.build();
    dataset.changeOrdering(
            {std::stoi(params.at(3).c_str()), std::stoi(params.at(4).c_str()), std::stoi(params.at(5).c_str())});

    if (params.at(2) == "1") {
        dataset.removeSample(0);
    }

    DatasetModifier::Modifier::CategoryId modifier(dataset);
    modifier.applyToColumn(0);
    modifier.applyToColumn(1);

    DatasetExporter::CSVExporter exporter(dataset);

    T_String outPath(params.at(6).c_str());
    mkdir(outPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    T_String indexPath(outPath);
    indexPath.append("index.csv");
    exporter.exportTo(indexPath);

    T_String map0Path(outPath);
    map0Path.append("map0.json");
    modifier.saveColumnMapTo(0, map0Path);

    T_String map1Path(outPath);
    map1Path.append("map1.json");
    modifier.saveColumnMapTo(1, map1Path);
}

int main(int argc, char *argv[]) {
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();

    run(argc, argv);

    return 0;
}