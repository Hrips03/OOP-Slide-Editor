#include "./includes/saveCmd.hpp"

saveCmd::saveCmd(std::string fileName) : m_fileName(fileName)
{
    m_doc = std::shared_ptr<Document>(new Document());
    //m_doc = Application::getInstance()->getDocument();
}

void saveCmd ::execute()
{
    m_doc->save(m_fileName);
}

std::shared_ptr<ICommand> saveCmd::clone() const
{
    return std::make_shared<saveCmd>(*this);
}
