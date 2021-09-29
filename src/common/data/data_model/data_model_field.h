//
// Created by Tyler on 9/26/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_DATA_MODEL_FIELD_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_DATA_MODEL_FIELD_H_

#include <stdexcept>
#include <string>

/**
 * Data Model Field identifier length
 * byte 0 = the field code
 * byte 1-3 = any metadata for the field
 */
const int8_t DMF_HEADER_LEN = 5;


class DataModelField {
public:
  /**
   * Returns the size of the field in bytes
   * @return
   */
  virtual size_t bytes() = 0;

  /**
   * Data model code, used for serializing / deserializing
   * @return
   */
  virtual int8_t code() = 0;

  /**
   * returns the string representation of the field
   * @return
   */
  virtual const char* extended_code() = 0;

  /**
   * the name of the field
   * @return
   */
  const char* name();

  /**
   * default constructor
   */
   DataModelField(int8_t*, size_t&);

   /**
   * default constructor
    */
   DataModelField(char*, const int8_t[DMF_HEADER_LEN]);

    /**
     * Write the field to a buffer
     */
    void write_to_buffer(int8_t*, size_t&);

    /**
     * Delete the constructed data
     */
    virtual ~DataModelField();

    /**
     * Copy Constructor
     * @param other
     * @return
     */
    DataModelField(const DataModelField& other);

    /**
     * Move Constructor
     * @param other
     */
    DataModelField(DataModelField&& other) noexcept ;

    /**
     * Copy Assignment
     * @param other
     * @return
     */
    DataModelField& operator=(const DataModelField& other);

    /**
     * Move Assignment
     * @param other
     * @return
     */
    DataModelField& operator=(DataModelField&& other) noexcept;

  protected:
   int8_t* _header;

private:
  size_t _name_len;
  char* _name;

};

#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_DATA_MODEL_FIELD_H_
