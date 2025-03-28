#pragma once

#include <string>
#include <unordered_set>

class ScFile
{
public:
  ScFile(std::string path);

  [[nodiscard]] std::string GetPath() const;

  void Write(std::string const & text);

  void Read(std::stringstream & text) const;

  [[nodiscard]] std::string GetName() const;

  [[nodiscard]] std::string GetExtension() const;

  [[nodiscard]] bool HasExtension(std::unordered_set<std::string> const & extensions) const;

private:
  std::string m_path;
};
