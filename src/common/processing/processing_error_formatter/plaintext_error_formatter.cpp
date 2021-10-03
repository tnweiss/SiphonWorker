//
// Created by Tyler on 10/3/2021.
//

#include "plaintext_error_formatter.h"


std::string siphon::PlaintextErrorFormatter::handle_process_exception(
    std::exception *ex, long query_id, long task_id, long step, Frame *frame,
    Processor *processor) {

  std::string ex_string("PROCESSING ERROR\nTask(");
  ex_string.append(std::to_string(task_id));
  ex_string.append(")\nStep(");
  ex_string.append(std::to_string(step));
  ex_string.append(")\nProcessor:\n");
  ex_string.append(processor->to_string());
  ex_string.append("Frame:\n");
  ex_string.append(frame->to_string());
  ex_string.append("Exception: ");
  ex_string.append(ex->what());

  return ex_string;
}