# Mini-_rt
Format: A <ratio> <R,G,B>
Exemple: A 0.2 255,255,255
```
- **ratio** : `float [0.0, 1.0]`
- **R,G,B** : `int,int,int` chaque valeur `[0, 255]`

### **C - Camera** (unique, obligatoire)
```
Format: C <x,y,z> <nx,ny,nz> <fov>
Exemple: C -50.0,0,20 0,0,1 70
```
- **x,y,z** : `float,float,float` (coordonnées viewpoint)
- **nx,ny,nz** : `float,float,float` vecteur normalisé `[-1.0, 1.0]` chaque axe
- **fov** : `int [0, 180]` (degrés)

### **L - Light** (unique, obligatoire)
```
Format: L <x,y,z> <brightness> <R,G,B>
Exemple: L -40.0,50.0,0.0 0.6 10,0,255
```
- **x,y,z** : `float,float,float` (position lumière)
- **brightness** : `float [0.0, 1.0]`
- **R,G,B** : `int,int,int` `[0, 255]` (non utilisé en mandatory)

### **sp - Sphere** (multiple)
```
Format: sp <x,y,z> <diameter> <R,G,B>
Exemple: sp 0.0,0.0,20.6 12.6 10,0,255
```
- **x,y,z** : `float,float,float` (centre)
- **diameter** : `float > 0`
- **R,G,B** : `int,int,int` `[0, 255]`

### **pl - Plane** (multiple)
```
Format: pl <x,y,z> <nx,ny,nz> <R,G,B>
Exemple: pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
```
- **x,y,z** : `float,float,float` (point dans le plan)
- **nx,ny,nz** : `float,float,float` vecteur normalisé `[-1.0, 1.0]`
- **R,G,B** : `int,int,int` `[0, 255]`

### **cy - Cylinder** (multiple)
```
Format: cy <x,y,z> <nx,ny,nz> <diameter> <height> <R,G,B>
Exemple: cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
