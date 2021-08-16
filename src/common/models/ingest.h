#include "json.hpp"
#include <vector>
#include <string>
#include "ParameterParse.h"

#ifndef INGEST_H
#define INGEST_H

namespace siphon {
    enum DataStructure (
        array,
        object
    );

    enum SiphonType {
        string,
        int
    };

    class DataModelField {
        public:
            DataModelField(nlohmann::json&);
            std::string name() {return this.name;};
            SiphonType type() {return this.type;};
            bool required() {return this.required;};
        private:
            std::string *name;
            SiphonType *type;
            bool *required;

    };

    class DataModel {
        public:
            DataModel(nlohmann::json)
            DataStructure dataStructure();
            std::vector<DataModelField> fields();
    };
}

#endif