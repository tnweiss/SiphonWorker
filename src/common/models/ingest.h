#include <vector>
#include <string>
#include "boost/format.hpp"
#include "nlohmann/json.hpp"

#include "parsing/parameter_parse.h"
#include "siphon_strings.hpp"

#ifndef SIPHON_INGEST_H
#define SIPHON_INGEST_H

namespace siphon {
    class DataModelField {
        public:
            explicit DataModelField(nlohmann::json& _data): data(_data) {
                // get the parameters to assure they exist
                this->name();
                this->type();
                this->description();
            };

            std::string name();
            SiphonType type();
            std::string description();
    private:
            nlohmann::json& data;
    };

    class DataModel {
        public:
            explicit DataModel(nlohmann::json&);
            DataStructure dataStructure();
            std::vector<DataModelField>* fields();
        private:
            std::vector<DataModelField>* _fields;
            DataStructure _data_structure;
    };
}

#endif