//
// Created by Tyler on 9/26/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_DATA_MODEL_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_DATA_MODEL_H_

#include <cstdint>
#include <vector>

#include "data_model_field.h"

namespace siphon {

static const int8_t DATA_MODEL_CODE_ARRAY = 1;
static const char *DATA_MODEL_CODE_EXTENDED_ARRAY = "Array";

static const int8_t DATA_MODEL_CODE_OBJECT = 2;
static const char *DATA_MODEL_CODE_EXTENDED_OBJECT = "Object";

static const std::pair<int8_t, const char *> DM_TYPES[] = {
    {DATA_MODEL_CODE_ARRAY, DATA_MODEL_CODE_EXTENDED_ARRAY},
    {DATA_MODEL_CODE_OBJECT, DATA_MODEL_CODE_EXTENDED_OBJECT}};

class DataModel {
public:
  /**
   * Initialize Data Model with a model type
   */
  explicit DataModel(int8_t);

  /**
   * Initialize Data Model with a model type extended
   */
  explicit DataModel(const char *);

  /**
   * Initialize data model from buffer.
   *
   * Bytes 0  : Model Type
   * Bytes 1-2: Number of fields
   * Bytes 3- : field data
   */
  explicit DataModel(int8_t *);

  /**
   * Destructor for the data model
   */
  ~DataModel();

  /**
   * get the model type
   * @return
   */
  int8_t model_type();

  /**
   * Get the extended model type (string)
   * @return
   */
  [[nodiscard]] const char *model_type_extended() const;

  /**
   * Used to get an integer that can be used to get the requested
   *   field more efficiently
   * @return
   */
  std::string frame_accessor(const char *);

  /**
   * Used to compare data models for equality
   * @return
   */
  bool operator==(DataModel &);

private:
  std::vector<DataModelField *> *_fields;
  int8_t _type;
};
}

#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_DATA_MODEL_H_
