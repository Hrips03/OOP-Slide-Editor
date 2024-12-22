// #include "ICommand.hpp"
// #include <vector>
// #include <iostream>
// #include "../../../Document/includes/document.hpp"
// #include "../../../Editor/addShapeAction.hpp"

// class changeGeometry : public ICommand
// {
//     int m_slideNumber; 
//     std::shared_ptr<Item> m_item;
//     std::shared_ptr<Editor> m_editor = nullptr;
// public:
//     changeGeometry(int slideNum, int itemNum);
//     void execute() override;
//     std::shared_ptr<ICommand> clone() const override;
// };