#pragma once

#include <string>
#include <sstream>
#include <cstdint>

#include <functional>
#include <unordered_set>

#include "translator/stream/sc_string_stream.h"

/*!
 * @brief The SCsStream class is responsible for generating sc-stream text for the translator.
 *
 * The SCsStream class provides methods for formatting and structuring the sc-stream text,
 * as well as for attaching additional information to the text.
 *
 * The class supports various formatting options, such as row formatting, offset formatting,
 * and tabulation. It also allows for setting the current command and defining attached information.
 *
 * The SCsStream class is designed to be used in conjunction with the ScSCnTex2SCsTranslator class,
 * which performs the actual translation of sc.n-represented *.tex files into *.scs files.
 */
class SCsStream : protected ScStringStream
{
public:
  /*!
   * @brief Constructs an SCsStream object with no initial content.
   */
  SCsStream();

  /*!
   * @brief Constructs an SCsStream object with the provided initial strings.
   * @param args The initial strings to be added to the SCsStream.
   */
  template <typename... Args>
  SCsStream(Args const &... args)
  {
    std::vector<std::string> vector{args...};

    for (auto const & item : vector)
      *this << item;
  }

  /*!
   * @brief Overloads the << operator to add a string to the SCsStream.
   * @param string The string to be added to the SCsStream.
   * @return A reference to the SCsStream object.
   */
  SCsStream & operator<< (std::string const & string) override;

  /*!
   * @brief Adds a row to the SCsStream using a provided function.
   * @param row A function that generates the row content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Row(std::function<void(SCsStream &)> const & row);

  /*!
   * @brief Adds a row to the SCsStream using a provided function.
   * @param row A function that generates the row content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Row(std::function<SCsStream()> const & row);

  /*!
   * @brief Adds an offset to the SCsStream using a provided function.
   * @param formatted A function that generates the offset content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Offset(std::function<void(SCsStream &)> const & formatted);

  /*!
   * @brief Adds an offset to the SCsStream using a provided function.
   * @param formatted A function that generates the offset content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Offset(std::function<SCsStream()> const & formatted);

  /*!
   * @brief Adds formatted content to the SCsStream using a provided function.
   * @param formatted A function that generates the formatted content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Formatted(std::function<void(SCsStream &)> const & formatted);

  /*!
   * @brief Adds pre-formatted content to the SCsStream using a provided function.
   * @param formatted A function that generates the pre-formatted content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & PreFormatted(std::function<void(SCsStream &)> const & formatted = {});

  /*!
   * @brief Adds formatted content to the SCsStream using a provided function.
   * @param formatted A function that generates the formatted content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Formatted(std::function<SCsStream()> const & formatted);

  /*!
   * @brief Adds tabulated content to the SCsStream using a provided function.
   * @param tabulated A function that generates the tabulated content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Tabulated(std::function<void(SCsStream &)> const & tabulated);

  /*!
   * @brief Adds tabulated content to the SCsStream using a provided function.
   * @param tabulated A function that generates the tabulated content.
   * @return A reference to the SCsStream object.
   */
  SCsStream & Tabulated(std::function<SCsStream()> const & tabulated);

  /*!
   * @brief Adds a tab to the SCsStream.
   * @return A reference to the SCsStream object.
   */
  SCsStream & AddTab();

  /*!
   * @brief Removes a tab from the SCsStream.
   * @return A reference to the SCsStream object.
   */
  SCsStream & RemoveTab();

  /*!
   * @brief Sets the current command for the SCsStream.
   * @param name The name of the current command.
   * @return A reference to the SCsStream object.
   */
  SCsStream & SetCurrentCommand(std::string const & name = "any");

  /*!
   * @brief Adds attached information to the SCsStream using the provided strings.
   * @param args The attached information to be added to the SCsStream.
   * @return A reference to the SCsStream object.
   */
  template <typename... Args>
  SCsStream & Attached(Args const &... args)
  {
    std::vector<std::string> vector{args...};
    for (auto const & item : vector)
      m_attached.emplace_back(item);

    return *this;
  }

  /*!
   * @brief Clears the SCsStream object, resetting its internal state.
   */
  static void Clear();

  /*!
   * @brief Converts the SCsStream object to a string.
   * @return The SCsStream content as a string.
   */
  operator std::string() override;

private:
  static std::string m_offset; ///< The offset for the SCsStream.
  static uint32_t m_indent;   ///< The indentation level for the SCsStream.
  static std::string m_semicolons; ///< The semicolons for the SCsStream.
  static std::string m_currentCommand; ///< The current command for the SCsStream.
  static std::string m_lastCommand; ///< The last command for the SCsStream.

  static std::vector<std::string> m_attached; ///< The attached information for the SCsStream.

  static std::unordered_map<std::string, std::vector<std::string>> m_formats; ///< The formatting options for the SCsStream.
  static std::unordered_set<std::string> m_begins; ///< The command list header begin names for the SCsStream.

  /*!
   * @brief Prepares the SCsStream object for formatting.
   */
  void PreFormat();

  /*!
   * @brief Defines the semicolons for the SCsStream object.
   * @return The semicolons as a string.
   */
  static std::string DefineSemicolons();

  /*!
   * @brief Adds a tab to the SCsStream.
   */
  static void Tab();

  /*!
   * @brief Removes a tab from the SCsStream.
   */
  static void Untab();

  /*!
   * @brief Sets the double semicolons for the SCsStream object.
   */
  static void SetDoubleSemicolons();

  /*!
   * @brief Unsets the double semicolons for the SCsStream object.
   */
  static void UnsetDoubleSemicolons();

  /*!
   * @brief Defines the endline for the SCsStream object.
   * @return The endline as a string.
   */
  static std::string DefineEndline();

  /*!
   * @brief Defines the offset for the SCsStream object.
   * @return The offset as a string.
   */
  static std::string DefineOffset();

  /*!
   * @brief Checks if the given name is a command header.
   * @param name The name to check.
   * @return True if the name is a command header, false otherwise.
   */
  static bool IsCommandHeader(std::string const & name);

  /*!
   * @brief Checks if the given name is the beginning of a command list header.
   * @param name The name to check.
   * @return True if the name is the beginning of a command list header, false otherwise.
   */
  static bool IsCommandListHeaderBegin(std::string const & name);

  /*!
   * @brief Checks if the given name is the end of a command list header.
   * @param name The name to check.
   * @return True if the name is the end of a command list header, false otherwise.
   */
  static bool IsCommandListHeaderEnd(std::string const & name);
};
