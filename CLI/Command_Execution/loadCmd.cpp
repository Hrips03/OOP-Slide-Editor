#include "./includes/loadCmd.hpp"

loadCmd::loadCmd(std::string fileName) : m_fileName(fileName)
{
    std::shared_ptr<Document> m_doc = std::shared_ptr<Document>(new Document());
}

void loadCmd ::execute()
{
    m_doc->load(m_fileName);
}

std::shared_ptr<ICommand> loadCmd::clone() const
{
    return std::make_shared<loadCmd>(*this);
}
