#ifndef CANVAS_H
#define CANVAS_H


class Canvas
{
  public:
    /** Default constructor */
    Canvas();
    /** Default destructor */
    virtual ~Canvas();
    /** Copy constructor
     *  \param other Object to copy from
     */
    Canvas(const Canvas& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Canvas& operator=(const Canvas& other);
    /** Access m_uiCount
     * \return The current value of m_uiCount
     */
    unsigned int GetCount() { return m_uiCount; }
    /** Set m_uiCount
     * \param val New value to set
     */
    void SetCount(unsigned int val) { m_uiCount = val; }
    /** Access m_bCanvasActive
     * \return The current value of m_bCanvasActive
     */
    bool GetbCanvasActive() { return m_bCanvasActive; }
    /** Set m_bCanvasActive
     * \param val New value to set
     */
    void SetbCanvasActive(bool val) { m_bCanvasActive = val; }
  protected:
  private:
    unsigned int m_uiCount; //!< Member variable "m_uiCount"
    bool m_bCanvasActive; //!< Member variable "m_bCanvasActive"
};

#endif // CANVAS_H
