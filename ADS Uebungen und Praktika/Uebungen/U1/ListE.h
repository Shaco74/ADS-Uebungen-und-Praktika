// Einfach VL
class ListE
{
public:
    // Konstruktor
    ListE() {};
    ListE(std::initializer_list<int> init) : m_length(0)
        { for (const int& item : init) this->add(item); }
    
    // Dekonstruktor
    ~ListE()
    {
        while (m_head != nullptr)
        {
            NodeE* tmp = m_head->next;
            delete m_head;
            m_head = tmp;
        }
    }
    
    // Add Methode welche am Ende der Liste einen
    // Knoten mit der Variable item anfuegt
    void add(const int& item)
    {
        m_length++;
        NodeE* new_node = new NodeE();
        new_node->item = item;
        if (m_tail == nullptr) m_head = new_node;
        else m_tail->next = new_node;
        
        m_tail = new_node;
    }
    
    // Print Methode um Liste auszugeben
    void print() const
    {
        NodeE* current = m_head;
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
    
    // Gibt die Laenge der Liste zurueck
    int length() const { return m_length; }
    
    // Swap Methode welche den Knoten an der stelle
    // Index mit dem naechsten tauscht
    bool swap(const int& index){
        NodeE *currentPtr = m_head;
          
        if(m_head != nullptr){
            for(int idx = 0; idx < index - 1; idx++){
                if(currentPtr->next != nullptr){
                    currentPtr = currentPtr->next;
                }
            }
            // when the for loop is finished the currentPtr should point to the element before the element at index
            if(currentPtr->next != nullptr){
                if(currentPtr == m_head && index == 0){
                    NodeE *targetNode = currentPtr->next;
                    currentPtr->next = targetNode->next;
                    currentPtr->next = targetNode->next;
                    targetNode->next = currentPtr;
                    m_head = targetNode;
                    return true;
                }
                
                NodeE *prevNode = currentPtr;
                NodeE *targetNode = currentPtr->next;
                if(currentPtr->next->next == nullptr){
                    return false;
                }
                NodeE *nextNode = currentPtr->next->next;
                
                prevNode->next = nextNode;
                targetNode->next = nextNode->next;
                nextNode->next = targetNode;
                
                if(m_tail == nextNode){
                    m_tail = targetNode;
                }
                
                return true;
            }
        }
        return false;
    }
    
    // Print Methode welche die Knoten rueckwaerts
    // (in O(n)) ausgibt. Wird bei Aufgabe 4 implementiert.
    void print_reversed() const;
    
private:
    NodeE* m_head;
    NodeE* m_tail;
    int m_length;
    
    // Hilf Methode fuer print reversed (wenn print reversed rekursiv
    // implementiert wird)
    void print_reversed_helper(NodeE* node) const;
};
