//
// Created by Tyler on 9/26/2021.
//

#ifndef SIPHON_SRC_TEST_COMMON_DATA_DATA_MODEL_FIELD_FIELD_DATA_HPP_
#define SIPHON_SRC_TEST_COMMON_DATA_DATA_MODEL_FIELD_FIELD_DATA_HPP_


//////////////////////////////////////////////  Data Model Header Data
/////////////////////////////////////////////  0  ( 1 ) 0  0  0  0  0  t    e    s    t    0
//static const int8_t dm_constructor_data[] = {1, 1, 0, 0, 0, 0, 0, 0, 116, 101, 115, 116, 0};
//static const size_t dm_constructor_data_size = sizeof(dm_constructor_data) / sizeof(dm_constructor_data[0]);

////////////////////////////////////////////  Int Field Data
//////////////////////////////////////////// |    Header    |         name         |     description     |
//////////////////////////////////////////// \0 \0 \0 \0 \0  t    e    s    t   \0  d   e   s   c   1  \0
static const int8_t int_constructor_data[] = {0, 0, 0, 0, 0, 116, 101, 115, 116, 0, 44, 65, 73, 63, 31, 0};
static const size_t int_constructor_data_size = sizeof(int_constructor_data) / sizeof(int_constructor_data[0]);


#endif // SIPHON_SRC_TEST_COMMON_DATA_DATA_MODEL_FIELD_FIELD_DATA_HPP_
