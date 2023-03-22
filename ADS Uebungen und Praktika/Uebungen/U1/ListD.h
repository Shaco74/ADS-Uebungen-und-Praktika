// Doppelt VL
class ListD
{
public:
    // Konstruktor
    ListD() { };
    ListD(std::initializer_list<int> init) : m_length(0)
        { for (const int& item : init) this->add(item); }
    
    // Dekonstruktor
    ~ListD()
    {
        if (m_head == nullptr) return;
        while (m_head->next != nullptr)
        {
            m_head = m_head->next;
            delete m_head->prev;
        }
        delete m_head;
    }
    
    // Add Methode welche am Ende der Liste einen Knoten mit der
    // Variable item anfuegt
    void add(const int& item)
    {
        m_length++;
        
        NodeD* new_node = new NodeD();
        new_node->item = item;
        new_node->prev = m_tail;
        
        if (m_tail == nullptr) m_head = new_node;
        else m_tail->next = new_node;
        
        m_tail = new_node;
    }
    
    // Print Methode um Liste auszugeben
    void print() const
    {
        NodeD* current = m_head;
        std::cout << "[";
        while (true)
        {
            std::cout << current->item;
            if (current->next != nullptr)
            {
                std::cout << ", ";
                current = current->next;
            }
            else break;
        }
        std::cout << "]" << std::endl;
    }
    
    // Print Methode um Liste rueckwaerts auszugeben
    void print_reversed() const
    {
        NodeD* current = m_tail;
        std::cout << "[";
        while (true)
        {
            std::cout << current->item;
            if (current->prev != nullptr)
            {
                std::cout << ", ";
                current = current->prev;
            }
            else break;
        }
        std::cout << "]" << std::endl;
    }
    
    // gibt die Laenge der Liste zurueck
    int length() const { return m_length; }
    
    // Swap Methode welche den Knoten an der stelle
    // Index mit dem naechsten tauscht
    bool swap(const int& index){
        NodeD *currentPtr = m_head;
          
        if(m_head != nullptr){
            // when the for loop is finished the currentPtr should point to the element at index
            for(int idx = 0; idx < index; idx++){
                if(currentPtr->next != nullptr){
                    currentPtr = currentPtr->next;
                }
            }
            if(currentPtr->next != nullptr) {
                NodeD *targetNode = currentPtr;
                NodeD *nextNode = currentPtr->next;
                NodeD *prevNode = currentPtr->prev;
                
                // case: currentPtr is at the beginning (index 0)
                if(currentPtr == m_head) {
                    targetNode->next = nextNode->next;
                    targetNode->prev = nextNode;
                    
                    // nextNode points to target now and the prev should be nullptr because the target was head
                    nextNode->next = targetNode;
                    nextNode->prev = nullptr;
                    
                    m_head = nextNode;
                    return true;
                }
                
                // set if
                if(prevNode != nullptr){
                    prevNode->next = nextNode;
                }
        
                targetNode->prev = nextNode;
                targetNode->next = nextNode->next;
                
                nextNode->next = targetNode;
                nextNode->prev = prevNode;
                
                if(m_tail == nextNode){
                    m_tail = targetNode;
                }
                
                return true;
            }
        }
        return false;
    }

private:
    NodeD* m_head;
    NodeD* m_tail;
    int m_length;
};
