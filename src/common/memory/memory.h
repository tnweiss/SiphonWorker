//
// Created by tyler on 8/31/21.
//

#ifndef SIPHON_SRC_COMMON_MEMORY_MEMORY_H_
#define SIPHON_SRC_COMMON_MEMORY_MEMORY_H_

class memory {
  virtual std::vector<std::vector<boost::any*>> readArrayFrames(std::string) = 0;
  virtual std::vector<std::vector<boost::any*>> readObjectFrames(std::string) = 0;
  virtual nlohmann::json readJson() = 0;

  virtual void setArrayFrames(std::string, std::vector<std::vector<boost::any>>) = 0;
};

#endif //SIPHON_SRC_COMMON_MEMORY_MEMORY_H_
