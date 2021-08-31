#ifndef SIPHON_FILTER_H
#define SIPHON_FILTER_H

#include <vector>
#include "boost/any.hpp"
#include "nlohmann/json.hpp"

namespace siphon {

    class Filter {
        public:
            virtual bool execute(boost::any[]&) = 0;
            virtual void parse(nlohmann::json job, nlohmann::json data_model) = 0;

            /**
             * 
             * 
             */
            void expand() {

            }

            void contract() {

            }

            Filter(nlohmann::json &d) {
                this->data = d;
            }

        private:
            nlohmann::json &data;

        protected:
            template<typename T>
            T get(){}
    };

};


#endif