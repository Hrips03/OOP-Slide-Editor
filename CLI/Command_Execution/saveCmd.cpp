#include "./includes/saveCmd.hpp"

saveCmd::saveCmd(std::string fileName) : m_fileName(fileName)
{
    std::shared_ptr<Document> m_doc = std::shared_ptr<Document>(new Document());
}

void saveCmd ::execute()
{
    m_doc->save(m_fileName);
}

std::shared_ptr<ICommand> saveCmd::clone() const
{
    return std::make_shared<saveCmd>(*this);
}
