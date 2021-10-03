//
// Created by Tyler on 10/2/2021.
//

#ifndef SIPHON_SRC_COMMON_PROCESSING_PROCESSING_ERROR_FORMATTER_H_
#define SIPHON_SRC_COMMON_PROCESSING_PROCESSING_ERROR_FORMATTER_H_

#include <string>

#include "processor.h"

namespace siphon {
class ProcessErrorFormatter {

  /**
   *
   * @param ex
   * @param query_id
   * @param task_id
   * @param step
   * @param frame
   * @param processor
   * @return
   */
  virtual std::string handle_process_exception(std::exception *ex,
                                               long query_id, long task_id,
                                               long step, Frame *frame,
                                               Processor *processor) = 0;
};

}
#endif // SIPHON_SRC_COMMON_PROCESSING_PROCESSING_ERROR_FORMATTER_H_
