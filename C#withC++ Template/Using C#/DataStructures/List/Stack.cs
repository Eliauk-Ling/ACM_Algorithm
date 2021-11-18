using System.Collections.Generic;
using System;

namespace DataStructures.List {
    ///Stack Data Structures(LIFO)
    
    public class Stack<T> : IEnumerable<T> where T : IEnumerable<T> {

        private ArrayList<T> _collection;
        public uint Count {
            get {
                return _collection.Count;
            }
        }

        
        public Stack() {
            _collection = new ArrayList<T>();
        }

        public

    }

}
