#pragma once

#include <memory>
#include <string>

#include "translator/commands/sc_scn_tex2scs_translations.h"

/*!
 * @brief Represents a prefix tree for managing identifiers in scn-text.
 *
 * This class provides methods for adding, retrieving, and managing identifiers in a prefix tree structure.
 * It also provides a method for dumping the tree structure for debugging purposes.
 */
class ScSCnPrefixTree
{
public:
  /*!
   * @brief Destructor.
   *
   * Frees the allocated memory for the prefix tree.
   */
  ~ScSCnPrefixTree();

  /*!
   * @brief Returns the singleton instance of the ScSCnPrefixTree class.
   *
   * @return The singleton instance of ScSCnPrefixTree.
   */
  static ScSCnPrefixTree & GetInstance();

  /*!
   * @brief Adds a new identifier to the prefix tree.
   *
   * @param key The key (identifier) to be added.
   * @param nodeType The type of the node (e.g., "sc_node", "sc_node_class", etc.).
   * @return The unique identifier (sys_id) of the added node.
   */
  std::string Add(std::string const & key, std::string const & nodeType);

    /*!
   * @brief Adds a new identifier to the prefix tree.
   *
   * @param key The key (identifier) to be added.
   * @param nodeTypeWithAdditionalClasses The type of the node (e.g., "sc_node", "sc_node_class", etc.)
     * and additional classes it should belong to.
   * @return The unique identifier (sys_id) of the added node.
   */
  std::string Add(std::string const & key, std::list<std::string> const & nodeTypeWithAdditionalClasses);

  /*!
   * @brief Retrieves the value associated with the given key from the prefix tree.
   *
   * @param key The key (identifier) to retrieve the value for.
   * @return The value associated with the given key, or an empty string if the key is not found.
   */
  std::string Get(std::string const & key);

  /*!
   * @brief Sets the new element system identifier for the prefix tree.
   *
   * @param elementSysId The new element system identifier.
   */
  void SetNewElementNumber(size_t elementSysId);

  /*!
   * @brief Retrieves a free element system identifier from the prefix tree.
   *
   * @return A free element system identifier, or an empty string if no free identifier is available.
   */
  std::string GetFreeElementSystemIdentifier();

  /*!
   * @brief Dumps the prefix tree structure for debugging purposes.
   *
   * @return A string representation of the prefix tree structure.
   */
  std::string Dump() const;

protected:
  /*!
   * @brief A pointer to the singleton instance of ScSCnPrefixTree.
   */
  static std::unique_ptr<ScSCnPrefixTree> m_instance;

  /*!
   * @brief Constructor.
   *
   * Initializes the prefix tree with default values.
   */
  ScSCnPrefixTree();

private:
  long long index; ///< The index for generating unique identifiers.

  ScSCnTexTranslations m_translations; ///< The translations for SCn TeX commands.
};
