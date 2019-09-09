import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.*;

class Node implements Comparable<Node> {
        int color;
        String name;
        boolean travelled;
        int degree;
        ArrayList<Node> adjacent;

        public Node() {

        }

        @Override
        public int compareTo(Node u) {
                if (getCreatedOn() == null || u.getCreatedOn() == null) {
                        return 0;
                }
                return getCreatedOn().compareTo(u.getCreatedOn());
        }

        public void addNode(Node n) {
                if (this.adjacent == null)
                        this.adjacent = new ArrayList<Node>();
                adjacent.add(n);
        }

        public Node(String name) {
                this.name = name;
        }

        public Node(int color, boolean travelled, int degree, ArrayList<Node> adjacent) {
                this.color = color;
                this.travelled = travelled;
                this.degree = degree;
                this.adjacent = adjacent;
        }

        public int getColor() {
                return this.color;
        }

        public void setColor(int color) {
                this.color = color;
        }

        public boolean isTravelled() {
                return this.travelled;
        }

        public boolean getTravelled() {
                return this.travelled;
        }

        public void setTravelled(boolean travelled) {
                this.travelled = travelled;
        }

        public int getDegree() {
                return this.degree;
        }

        public void setDegree(int degree) {
                this.degree = degree;
        }

        public ArrayList<Node> getAdjacent() {
                return this.adjacent;
        }

        public void setAdjacent(ArrayList<Node> adjacent) {
                this.adjacent = adjacent;
        }

        public Node color(int color) {
                this.color = color;
                return this;
        }

        public Node travelled(boolean travelled) {
                this.travelled = travelled;
                return this;
        }

        public Node degree(int degree) {
                this.degree = degree;
                return this;
        }

        public Node adjacent(ArrayList<Node> adjacent) {
                this.adjacent = adjacent;
                return this;
        }

        public String getName() {
                return name;
        }

        public void setName(String name) {
                this.name = name;
        }

}

public class GraphColoring {
        public static void main(String[] args) {
                /** ------------------Preprocessing------------------ */
                // List <Integer> one = new ArrayList<Integer>();
                // one.push(2);

                // List <Integer> two = new ArrayList<Integer>();
                // two.push(1); two.push(3); two.push(4); two.push(5);

                // List <Integer> three = new ArrayList<Integer>();
                // three.push(5); three.push(2);

                // List <Integer> four = new ArrayList<Integer>();
                // four.push(5); four.push(2);

                // List<Integer> five = new ArrayList<Integer>();
                // five.push(3);
                // five.push(4);
                // five.push(2);

                // HashMap <Integer, ArrayList<Integer>> adjList = new LinkedHashMap<Integer,
                // ArrayList<Integer>>();
                // adjList.put(1, one);
                // adjList.put(2, two);
                // adjList.put(3, three);
                // adjList.put(4, four);
                // adjList.put(5, five);

                /** ------------------------------------------------ */

                List<Node> nodes = new ArrayList<Node>();

                Node one = new Node("1");
                Node two = new Node("2");
                Node three = new Node("3");
                Node four = new Node("4");
                Node five = new Node("5");

                one.addNode(two);
                two.addNode(three);
                two.addNode(four);
                two.addNode(five);
                two.addNode(one);
                three.addNode(five);
                three.addNode(two);
                four.addNode(five);
                four.addNode(two);
                five.addNode(three);
                five.addNode(four);
                five.addNode(two);

                nodes.add(one);
                nodes.add(two);
                nodes.add(three);
                nodes.add(four);
                nodes.add(five);

                for (Node n : nodes) {
                        n.setDegree(n.getAdjacent().size());
                        System.out.println(n.getDegree());
                }

                nodes.sort(c);

        }
}