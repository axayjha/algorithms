package bfs;

/**
 *
 * @author akshay
 */
import java.util.*;
import java.util.LinkedList;
import java.util.Hashtable;
import java.io.*;
public class bfs {

    /**
     * @param args the command line arguments
     */    
    
    public static void main(String[] args) {
        
    vertex a = new vertex("a");
    vertex b = new vertex("b");
    vertex c = new vertex("c");
    vertex d = new vertex("d");
    vertex e = new vertex("e");
    vertex f = new vertex("f");
    vertex g = new vertex("g");
    
    List<vertex> A = new ArrayList<vertex>(){{add(b); add(c);}};
    List<vertex> B = Arrays.asList(a,d,f,e);
    List<vertex> C = Arrays.asList(a);
    List<vertex> D = Arrays.asList(b);
    List<vertex> E = Arrays.asList(b,g);
    List<vertex> F = Arrays.asList(b);
    List <vertex>G = Arrays.asList(e);
    Map<String, List> adj = new Hashtable<String, List>();
    adj.put("a", A);
    adj.put("b", B);
    adj.put("c", C);
    adj.put("d", D);
    adj.put("e", E);
    adj.put("f", F);
    adj.put("g", G);    
    Queue <vertex> Q = new LinkedList<>();
    a.setColour("black");
    Q.add(a);
    while(Q.size() != 0)
    {
        vertex v = Q.remove();

        for(int i=0; i< adj.get(v.getName()).size(); i++){
            if(((vertex)adj.get(v.getName()).get(i)).getColour().equals("white"))
            {
                ((vertex)adj.get(v.getName()).get(i)).setColour("gray");
                Q.add(((vertex)adj.get(v.getName()).get(i)));
                System.out.println(((vertex)adj.get(v.getName()).get(i)).getName());
            }
        }
        
        v.setColour("black");
    }
    
             
    }
    
}

class vertex{
    String name, colour;
    vertex(){};
    vertex(String name){
        this.name = name;
        colour = "white";
    }
    public void setColour(String c){
        this.colour = c;
    }
    public String getColour(){
        return this.colour;
    }
    public String getName(){
        return this.name;
    }
}
