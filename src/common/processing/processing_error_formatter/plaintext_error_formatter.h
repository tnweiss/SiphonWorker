//
// Created by Tyler on 10/3/2021.
//

#ifndef SIPHON_SRC_COMMON_PROCESSING_PROCESSING_ERROR_FORMATTER_PLAINTEXT_ERROR_FORMATTER_H_
#define SIPHON_SRC_COMMON_PROCESSING_PROCESSING_ERROR_FORMATTER_PLAINTEXT_ERROR_FORMATTER_H_

#include "../processing_error_formatter.h"


namespace siphon {
class PlaintextErrorFormatter {
  std::string handle_process_exception(std::exception *ex, long query_id,
                                       long task_id, long step, Frame *frame,
                                       Processor *processor);
};
}

#endif // SIPHON_SRC_COMMON_PROCESSING_PROCESSING_ERROR_FORMATTER_PLAINTEXT_ERROR_FORMATTER_H_
