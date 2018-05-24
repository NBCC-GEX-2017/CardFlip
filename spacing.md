#Spacing, Stretching, and Struts

* `addSpacing(int size)` adds a fixed number of pixels to the end of the layout.

* `addStretch(int stretch = 0)` adds a stretchable number of pixels. It starts at a minimum amount and stretches to use all available space. In the event of multiple stretches in the same layout, this can be used as a growth factor.

* `addStrut(int size)` imposes a minimum size to the perpendicular dimension (i.e., the width of a QVBoxLayout or the height of an QHBoxLayout).

**addSpacing** and **addStretch** will add the space and stretch where they are added in the layout, so: 

```C++
layout->addWidget(button_1);   
layout->addStretch(1);   
layout->addWidget(button_2);    
```
will add the stretch between the two buttons pushing them appart, whereas 

```C++
layout->addStretch(1);  
layout->addWidget(button_1);    
layout->addWidget(button_2);    
```
will add the stretch before the buttons, pushing them both to the right in a horizontal layout, or down in a vertical layout. 

