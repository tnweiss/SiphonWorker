#include "ingest.h"

namespace siphon {
    DataModel::DataModel(nlohmann::json& data) {
        this->_data_structure = parameterParseEnum<DataStructure>(data, siphon::DATA_STRUCTURE_KEY);
        this->_fields = parameterParseArray<DataModelField>(data, siphon::FIELDS_KEY);
    }

    DataStructure DataModel::dataStructure() {
        return this->_data_structure;
    }

    std::vector<DataModelField>* DataModel::fields() {
        return this->_fields;
    }

    std::string DataModelField::description() {
        return parameterParse<std::string>(this->data, siphon::DESCRIPTION_KEY, "");
    }

    std::string DataModelField::name() {
        return parameterParse<std::string>(this->data, siphon::NAME_KEY);
    }

    SiphonType DataModelField::type() {
        return parameterParseEnum<SiphonType>(this->data, siphon::TYPE_KEY);
    }
}