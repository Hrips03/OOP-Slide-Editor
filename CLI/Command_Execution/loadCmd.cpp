#include "./includes/loadCmd.hpp"

loadCmd::loadCmd(std::string fileName) : m_fileName(fileName)
{
    m_doc = std::shared_ptr<Document>(new Document());
    //m_doc = Application::getInstance()->getDocument();
}

void loadCmd ::execute()
{
    m_doc->load(m_fileName);
}

std::shared_ptr<ICommand> loadCmd::clone() const
{
    return std::make_shared<loadCmd>(*this);
}
